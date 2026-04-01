var assert = require('assert');
var solution088 = require('../src/euler/solution088');

describe('Solution088', function() {
  describe('answer', function() {
    it('will answer problem 088', function() {
      assert.equal(solution088.answer(), 7587457);
    });
  });
});