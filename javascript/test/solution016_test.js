var assert = require('assert');
var solution016 = require('../src/euler/solution016');

describe('Solution016', function() {
  describe('answer', function() {
    it('will answer problem 016', function() {
      assert.equal(solution016.answer(), 1366);
    });
  });
});