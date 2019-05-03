var assert = require('assert');
var solution005 = require('../src/euler/solution005');

describe('Solution005', function() {
  describe('answer', function() {
    it('will answer problem 005', function() {
      assert.equal(solution005.answer(), 232792560);
    });
  });
});
