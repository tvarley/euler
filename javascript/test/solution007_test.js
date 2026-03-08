var assert = require('assert');
var solution007 = require('../src/euler/solution007');

describe('Solution007', function() {
  describe('answer', function() {
    it('will answer problem 007', function() {
      assert.equal(solution007.answer(), 104743);
    });
  });
});